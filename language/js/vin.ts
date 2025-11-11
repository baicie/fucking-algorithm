function validateVIN(VIN) {
  // 检查VIN长度
  if (VIN.length !== 17)
    return false

  // 检查VIN格式
  if (!/^[A-HJ-NPR-Z\d]{17}$/i.test(VIN))
    return false

  // 计算校验位
  const weights = [8, 7, 6, 5, 4, 3, 2, 10, 0, 9, 8, 7, 6, 5, 4, 3, 2]
  const checkDigit = VIN.charAt(8)
  const vinArray = VIN.toUpperCase().split('')

  let sum = 0
  for (let i = 0; i < 17; i++) {
    sum += (vinArray[i] === 'X') ? 10 : Number.parseInt(vinArray[i], 36)
    sum *= weights[i]
  }

  const remainder = sum % 11
  const calculatedCheckDigit = (remainder === 10) ? 'X' : String(remainder)
  console.log(calculatedCheckDigit, checkDigit)

  return calculatedCheckDigit === checkDigit
}

console.log(validateVIN('LSVHH133X32224597'))
